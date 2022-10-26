@echo off
:start
set /p min=等待分钟
if %min%==-1 goto end
set /p sec=等待秒钟
set /p announce=提醒内容
set /a time=60*%min%+%sec%
TIMEOUT /t %time%
start "" "D:\大学攻略\1.花球啦啦操大学规定动作 音乐.mp3"
echo.
echo %announce%
echo.
goto start
:end
pause