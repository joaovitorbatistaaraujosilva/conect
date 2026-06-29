@echo off
echo Building Flutter in Release Mode...
cd C:\Projetos\conect\flutter
call flutter build windows --release

echo Copying librustdesk.dll to Release folder...
copy /Y "C:\Projetos\conect\target\release\librustdesk.dll" "C:\Projetos\conect\flutter\build\windows\x64\runner\Release\librustdesk.dll"

echo Installing Python requirements...
cd C:\Projetos\conect\libs\portable
py -3 -m pip install -r requirements.txt

echo Running Packer...
py -3 generate.py -f ..\..\flutter\build\windows\x64\runner\Release -o . -e ..\..\flutter\build\windows\x64\runner\Release\rustdesk.exe

echo Moving finished executable to root...
move /Y ..\..\target\release\rustdesk-portable-packer.exe ..\..\RustDesk.exe

echo Done! Your final app is at C:\Projetos\conect\RustDesk.exe
pause
