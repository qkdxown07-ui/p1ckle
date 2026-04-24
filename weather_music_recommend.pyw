import requests
from win11toast import toast

def get_location():
    try:
        # Get location via IP
        response = requests.get("https://ipinfo.io/json", timeout=5)
        data = response.json()
        loc = data.get('loc', '37.5665,126.9780') # Default to Seoul
        lat, lon = loc.split(',')
        return lat, lon
    except Exception:
        return '37.5665', '126.9780'

def get_weather(lat, lon):
    try:
        # Use Open-Meteo API (free, no API key required)
        url = f"https://api.open-meteo.com/v1/forecast?latitude={lat}&longitude={lon}&current_weather=true"
        response = requests.get(url, timeout=5)
        data = response.json()
        code = data.get('current_weather', {}).get('weathercode', 0)
        return code
    except Exception:
        return 0 # Default to clear

def categorize_weather(code):
    # WMO Weather interpretation codes
    # 0: 맑음
    # 71, 73, 75, 77, 85, 86, 96, 99: 눈
    # 기타: 흐림 또는 비 (1, 2, 3, 45, 48, 51, 53, 55, 61, 63, 65, 등등)
    if code == 0:
        return "맑음", "K-pop, 댄스"
    elif code in [71, 73, 75, 77, 85, 86, 96, 99]:
        return "눈", "클래식, 재즈"
    else:
        return "흐림이나 비", "발라드, R&B"

def main():
    lat, lon = get_location()
    weather_code = get_weather(lat, lon)
    weather_name, genres = categorize_weather(weather_code)
    
    title = "🌤️ 오늘의 날씨 맞춤 음악 장르 추천"
    body = f"현재 날씨는 [{weather_name}]입니다.\n오늘 같은 날씨에는 {genres} 음악을 추천해요!"
    
    # 팝업 알림 (Toast Notification)
    toast(title, body, duration="long")

if __name__ == "__main__":
    main()
