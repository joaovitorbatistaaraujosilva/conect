@echo off
echo Iniciando o Servidor RustDesk (Rendezvous e Relay)...

cd C:\Projetos\rustdesk-server-master\target\release

echo Iniciando HBBS (Servidor de ID)...
start "RustDesk ID Server (hbbs)" hbbs.exe

echo Iniciando HBBR (Servidor de Relay)...
start "RustDesk Relay Server (hbbr)" hbbr.exe

echo Servidores iniciados em novas janelas!
pause
