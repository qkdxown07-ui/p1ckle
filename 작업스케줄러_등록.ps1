$taskName = "WeatherMusicRecommend"
$scriptPath = "$PSScriptRoot\weather_music_recommend.pyw"

# Check if Python is available
$pythonPath = (Get-Command pythonw.exe -ErrorAction SilentlyContinue).Source
if (-not $pythonPath) {
    Write-Host "Python(pythonw.exe)을 찾을 수 없습니다. Python이 설치되어 있고 PATH에 추가되어 있는지 확인하세요."
    Pause
    exit
}

Write-Host "작업 스케줄러에 등록 중..."

# Delete existing task if it exists
$existingTask = Get-ScheduledTask -TaskName $taskName -ErrorAction SilentlyContinue
if ($existingTask) {
    Unregister-ScheduledTask -TaskName $taskName -Confirm:$false
}

# Create action to run pythonw with the script
$action = New-ScheduledTaskAction -Execute $pythonPath -Argument "`"$scriptPath`""

# Create trigger for user logon
$trigger = New-ScheduledTaskTrigger -AtLogOn

# Define settings (no execution time limit, don't stop on battery)
$settings = New-ScheduledTaskSettingsSet -AllowStartIfOnBatteries -DontStopIfGoingOnBatteries -ExecutionTimeLimit (New-TimeSpan -Days 0)

# Register the scheduled task
Register-ScheduledTask -TaskName $taskName -Action $action -Trigger $trigger -Settings $settings -Description "로그인 시 현재 날씨를 확인하고 음악 장르를 추천합니다." | Out-Null

Write-Host "등록 완료! 이제 컴퓨터를 켤 때마다 날씨 맞춤 음악 장르를 추천해줍니다."
Write-Host "테스트로 지금 한 번 실행합니다..."
Start-Process -FilePath $pythonPath -ArgumentList "`"$scriptPath`""

Pause
