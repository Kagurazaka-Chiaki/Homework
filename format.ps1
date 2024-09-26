
$folder_path = $args[0]

$cpp_files = Get-ChildItem -Path $folder_path -Recurse -Filter *.cpp

$hpp_files = Get-ChildItem -Path $folder_path -Recurse -Filter *.hpp

$c_files = Get-ChildItem -Path $folder_path -Recurse -Filter *.c

$h_files = Get-ChildItem -Path $folder_path -Recurse -Filter *.h

$files = $cpp_files + $hpp_files + $c_files + $h_files

foreach ($file in $files) {
    Write-Host "Formatting $($file.FullName)..."
    & "clang-format" -i "$($file.FullName)"
}

Write-Host "Formatting completed."
