# =============================================
# C → D 드라이브 사용자 데이터 이동 스크립트
# =============================================
# 실행 전 주의: 관리자 권한으로 실행해야 합니다.

$ErrorActionPreference = "Continue"
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8

# ─── 1. 바탕화면 과제 폴더 이동 ───
Write-Host "`n[1/5] 바탕화면 과제 폴더 이동 중..." -ForegroundColor Cyan

$desktopSrc = "C:\Users\01071703128\Desktop"
$desktopDst = "D:\01071703128\Desktop"

if (-not (Test-Path $desktopDst)) { New-Item -Path $desktopDst -ItemType Directory -Force | Out-Null }

$assignmentFolders = @(
    "sweets",
    "영어 회화 과제",
    "웹 프로그래밍 과제",
    "인공지능 기초 과제",
    "정보통신개론 과제",
    "파이선 프로그래밍 과제"
)

# Also move the text file
$assignmentFiles = @(
    "선배님 인터뷰 질문.txt"
)

foreach ($folder in $assignmentFolders) {
    $src = Join-Path $desktopSrc $folder
    $dst = Join-Path $desktopDst $folder
    if (Test-Path $src) {
        if (-not (Test-Path $dst)) {
            Write-Host "  이동: $folder -> D:\01071703128\Desktop\" -ForegroundColor Green
            Move-Item -Path $src -Destination $dst -Force
        } else {
            Write-Host "  이미 존재 (스킵): $dst" -ForegroundColor Yellow
        }
    }
}

foreach ($file in $assignmentFiles) {
    $src = Join-Path $desktopSrc $file
    $dst = Join-Path $desktopDst $file
    if (Test-Path $src) {
        if (-not (Test-Path $dst)) {
            Write-Host "  이동: $file -> D:\01071703128\Desktop\" -ForegroundColor Green
            Move-Item -Path $src -Destination $dst -Force
        } else {
            Write-Host "  이미 존재 (스킵): $dst" -ForegroundColor Yellow
        }
    }
}

Write-Host "  완료!" -ForegroundColor Green

# ─── 2. Documents 사용자 데이터 이동 ───
Write-Host "`n[2/5] Documents 사용자 파일 이동 중..." -ForegroundColor Cyan

$docsSrc = "C:\Users\01071703128\Documents"
$docsDst = "D:\01071703128\Documents"

if (-not (Test-Path $docsDst)) { New-Item -Path $docsDst -ItemType Directory -Force | Out-Null }

# Move user-created files (exclude system files like desktop.ini, junction points)
$docsItems = Get-ChildItem -Path $docsSrc -Force | Where-Object {
    $_.Name -notin @("desktop.ini", "My Music", "My Pictures", "My Videos") -and
    -not $_.Attributes.HasFlag([System.IO.FileAttributes]::ReparsePoint)
}

foreach ($item in $docsItems) {
    $dst = Join-Path $docsDst $item.Name
    if (-not (Test-Path $dst)) {
        Write-Host "  이동: $($item.Name)" -ForegroundColor Green
        Move-Item -Path $item.FullName -Destination $dst -Force
    } else {
        Write-Host "  이미 존재 (스킵): $($item.Name)" -ForegroundColor Yellow
    }
}

Write-Host "  완료!" -ForegroundColor Green

# ─── 3. Downloads 대용량 파일 이동 ───
Write-Host "`n[3/5] Downloads 대용량 파일 이동 중..." -ForegroundColor Cyan

$dlSrc = "C:\Users\01071703128\Downloads"
$dlDst = "D:\01071703128\Download"

if (-not (Test-Path $dlDst)) { New-Item -Path $dlDst -ItemType Directory -Force | Out-Null }

$dlItems = Get-ChildItem -Path $dlSrc -Force | Where-Object {
    $_.Name -ne "desktop.ini" -and
    -not $_.Attributes.HasFlag([System.IO.FileAttributes]::ReparsePoint)
}

foreach ($item in $dlItems) {
    $dst = Join-Path $dlDst $item.Name
    if (-not (Test-Path $dst)) {
        Write-Host "  이동: $($item.Name)" -ForegroundColor Green
        Move-Item -Path $item.FullName -Destination $dst -Force
    } else {
        Write-Host "  이미 존재 (스킵): $($item.Name)" -ForegroundColor Yellow
    }
}

Write-Host "  완료!" -ForegroundColor Green

# ─── 4. PyCharmMiscProject 이동 ───
Write-Host "`n[4/5] PyCharmMiscProject 이동 중..." -ForegroundColor Cyan

$pycharmSrc = "C:\Users\01071703128\PyCharmMiscProject"
$pycharmDst = "D:\01071703128\PyCharmMiscProject"

if (Test-Path $pycharmSrc) {
    if (-not (Test-Path $pycharmDst)) {
        Write-Host "  이동: PyCharmMiscProject -> D:\01071703128\" -ForegroundColor Green
        Move-Item -Path $pycharmSrc -Destination $pycharmDst -Force
    } else {
        Write-Host "  이미 존재 (스킵)" -ForegroundColor Yellow
    }
}

Write-Host "  완료!" -ForegroundColor Green

# ─── 5. 윈도우 기본 폴더 경로를 D 드라이브로 변경 ───
Write-Host "`n[5/5] 윈도우 기본 라이브러리 폴더 경로 변경 중..." -ForegroundColor Cyan

$shellFolders = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Explorer\User Shell Folders"

# Create destination folders
$folderMappings = @{
    "Personal"       = "D:\01071703128\Documents"      # 문서
    "{374DE290-123F-4565-9164-39C4925E467B}" = "D:\01071703128\Download" # 다운로드
    "My Pictures"    = "D:\01071703128\Pictures"        # 사진
    "My Video"       = "D:\01071703128\Videos"          # 비디오
    "My Music"       = "D:\01071703128\Music"           # 음악
    "Desktop"        = "D:\01071703128\Desktop"         # 바탕화면
}

foreach ($key in $folderMappings.Keys) {
    $newPath = $folderMappings[$key]
    if (-not (Test-Path $newPath)) { New-Item -Path $newPath -ItemType Directory -Force | Out-Null }
    
    try {
        Set-ItemProperty -Path $shellFolders -Name $key -Value $newPath -Type ExpandString
        Write-Host "  변경: $key -> $newPath" -ForegroundColor Green
    } catch {
        Write-Host "  실패: $key - $($_.Exception.Message)" -ForegroundColor Red
    }
}

Write-Host "  완료!" -ForegroundColor Green

# ─── 완료 ───
Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host " 이동 작업이 완료되었습니다!" -ForegroundColor Green
Write-Host " 변경사항을 완전히 적용하려면 로그아웃 후 다시 로그인하세요." -ForegroundColor Yellow
Write-Host "========================================`n" -ForegroundColor Cyan
