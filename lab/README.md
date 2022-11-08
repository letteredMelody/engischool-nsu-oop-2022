Лабораторная 2-1. Компилятор Clang 12.0.5 x86_64-apple-darwin20.6.0

Дополнительного функционала добавлено не было.

Для компиляции всех файлов в директории в VSCode одновременно, можно добавить в "code-runner.executorMap": { "cpp": "cd $dir && clang++ -std=c++17 *.cpp -o $fileName -o $fileNameWithoutExt & $dir$fileNameWithoutExt", }

Либо запускать с помощью CMake.
