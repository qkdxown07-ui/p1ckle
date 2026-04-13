"""
오늘의 추천곡 - Daily Song Recommendation
Windows 토스트 알림으로 Apple Music 라이브러리에서 매일 한 곡을 추천합니다.
하루에 한 번만 작동하며, 같은 날 2회 이상 실행 시 아무 동작도 하지 않습니다.
"""

import os
import sys
import json
import random
import datetime
import re

# ─── 설정 ─── 
APPLE_MUSIC_DIR = r"C:\Users\01071703128\Music\Apple Music\Media\Apple Music"
BACKUP_MUSIC_DIR = r"D:\Apple Music\다운로드 된 음악"
LOG_FILE = r"D:\01071703128\.daily_song_log.json"
MUSIC_EXTENSIONS = {'.m4p', '.m4a', '.mp3', '.aac', '.flac', '.wav', '.aiff', '.alac'}


def get_music_files():
    """Apple Music 라이브러리에서 모든 음악 파일을 수집합니다."""
    music_files = []
    
    search_dirs = [APPLE_MUSIC_DIR, BACKUP_MUSIC_DIR]
    
    for search_dir in search_dirs:
        if not os.path.exists(search_dir):
            continue
        for root, dirs, files in os.walk(search_dir):
            for f in files:
                ext = os.path.splitext(f)[1].lower()
                if ext in MUSIC_EXTENSIONS:
                    music_files.append({
                        'filename': f,
                        'path': os.path.join(root, f),
                        'artist': extract_artist(root, search_dir),
                        'album': extract_album(root),
                        'title': extract_title(f)
                    })
    
    return music_files


def extract_artist(filepath, base_dir):
    """폴더 구조에서 아티스트명을 추출합니다."""
    try:
        rel = os.path.relpath(filepath, base_dir)
        parts = rel.split(os.sep)
        if len(parts) >= 1:
            return parts[0]
    except:
        pass
    return "Unknown Artist"


def extract_album(filepath):
    """폴더 구조에서 앨범명을 추출합니다."""
    try:
        return os.path.basename(filepath)
    except:
        return "Unknown Album"


def extract_title(filename):
    """파일명에서 곡 제목을 추출합니다."""
    name = os.path.splitext(filename)[0]
    # Remove track numbers like "01 ", "1-01 ", "05 "
    name = re.sub(r'^[\d]+-?[\d]*\s+', '', name)
    return name


def load_log():
    """로그 파일을 읽어옵니다."""
    if os.path.exists(LOG_FILE):
        try:
            with open(LOG_FILE, 'r', encoding='utf-8') as f:
                return json.load(f)
        except:
            pass
    return {}


def save_log(data):
    """로그 파일을 저장합니다."""
    log_dir = os.path.dirname(LOG_FILE)
    if not os.path.exists(log_dir):
        os.makedirs(log_dir, exist_ok=True)
    with open(LOG_FILE, 'w', encoding='utf-8') as f:
        json.dump(data, f, ensure_ascii=False, indent=2)


def show_notification(title, message):
    """Windows 토스트 알림을 표시합니다."""
    try:
        from plyer import notification
        notification.notify(
            title=title,
            message=message,
            app_name="오늘의 추천곡 🎵",
            timeout=10
        )
        return True
    except Exception as e:
        # Fallback: Windows native PowerShell toast
        try:
            import subprocess
            ps_script = f'''
            [Windows.UI.Notifications.ToastNotificationManager, Windows.UI.Notifications, ContentType = WindowsRuntime] > $null
            $template = [Windows.UI.Notifications.ToastNotificationManager]::GetTemplateContent([Windows.UI.Notifications.ToastTemplateType]::ToastText02)
            $textNodes = $template.GetElementsByTagName("text")
            $textNodes.Item(0).AppendChild($template.CreateTextNode("{title}")) > $null
            $textNodes.Item(1).AppendChild($template.CreateTextNode("{message}")) > $null
            $toast = [Windows.UI.Notifications.ToastNotification]::new($template)
            [Windows.UI.Notifications.ToastNotificationManager]::CreateToastNotifier("오늘의추천곡").Show($toast)
            '''
            subprocess.run(["powershell", "-Command", ps_script], capture_output=True)
            return True
        except:
            return False


def main():
    today = datetime.date.today().isoformat()  # "2026-04-13"
    
    # 로그 확인 - 오늘 이미 추천했는지 체크
    log = load_log()
    if log.get("last_date") == today:
        # 오늘 이미 추천곡을 보여줬으므로 종료
        sys.exit(0)
    
    # 음악 파일 수집
    music_files = get_music_files()
    
    if not music_files:
        show_notification(
            "오늘의 추천곡 🎵",
            "Apple Music 라이브러리에서 음악을 찾을 수 없습니다.\n음악을 다운로드해주세요!"
        )
        sys.exit(0)
    
    # 오늘의 곡 랜덤 선정 (날짜 기반 시드로 같은 날에는 항상 같은 곡)
    random.seed(today)
    song = random.choice(music_files)
    
    # 알림 표시
    title = "🎵 오늘의 추천곡"
    message = f"♬ {song['title']}\n🎤 {song['artist']}\n💿 {song['album']}"
    
    show_notification(title, message)
    
    # 로그 저장
    log["last_date"] = today
    log["last_song"] = {
        "title": song['title'],
        "artist": song['artist'],
        "album": song['album'],
        "filename": song['filename']
    }
    
    # 히스토리 기록
    if "history" not in log:
        log["history"] = []
    log["history"].append({
        "date": today,
        "title": song['title'],
        "artist": song['artist']
    })
    
    save_log(log)


if __name__ == "__main__":
    main()
