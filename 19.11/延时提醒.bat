@echo off
:start
set /p min=�ȴ�����
if %min%==-1 goto end
set /p sec=�ȴ�����
set /p announce=��������
set /a time=60*%min%+%sec%
TIMEOUT /t %time%
start "" "D:\��ѧ����\1.���������ٴ�ѧ�涨���� ����.mp3"
echo.
echo %announce%
echo.
goto start
:end
pause