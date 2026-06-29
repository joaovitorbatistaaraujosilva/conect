@echo off
echo Initializing MSVC Environment...
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"

echo Setting Environment Variables...
set VCPKG_ROOT=C:\vcpkg
set LIBCLANG_PATH=C:\Program Files\LLVM\bin
set PATH=C:\Program Files\LLVM\bin;%PATH%

echo Running cargo build...
cargo build --features flutter --release
