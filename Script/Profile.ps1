
function prompt {

    # Assign Windows Title Text
    $host.ui.RawUI.WindowTitle = "Current Folder: $pwd"

    # Configure current user, current folder and date outputs
    $CmdPromptCurrentFolder = $pwd
    # $CmdPromptCurrentFolder = Split-Path -Path $pwd -Leaf
    $CmdPromptUser = [Security.Principal.WindowsIdentity]::GetCurrent();
    $Date = Get-Date -Format 'HH:mm:ss'

    # Test for Admin / Elevated
    $IsAdmin = (New-Object Security.Principal.WindowsPrincipal ([Security.Principal.WindowsIdentity]::GetCurrent())).IsInRole([Security.Principal.WindowsBuiltinRole]::Administrator)

    # Calculate execution time of last cmd and convert to milliseconds, seconds or minutes
    $LastCommand = Get-History -Count 1
    if ($lastCommand) { $RunTime = ($lastCommand.EndExecutionTime - $lastCommand.StartExecutionTime).TotalSeconds }

    if ($RunTime -ge 60) {
        $ts = [timespan]::fromseconds($RunTime)
        $min, $sec = ($ts.ToString("mm\:ss")).Split(":")
        $ElapsedTime = -join ($min, " min ", $sec, " sec")
    }
    else {
        $ElapsedTime = [math]::Round(($RunTime), 2)
        $ElapsedTime = -join (($ElapsedTime.ToString()), " sec")
    }

    # Decorate the CMD Prompt
    Write-Host "$env:CONDA_PROMPT_MODIFIER" -NoNewline
    Write-host (
        $( if ($IsAdmin) { 'ADMIN ' } else { '' } )
    ) -NoNewline
    # -BackgroundColor DarkRed -ForegroundColor White -NoNewline
    Write-Host "$($CmdPromptUser.Name.split("\")[1]) " -NoNewline
    # -BackgroundColor DarkBlue -ForegroundColor White -NoNewline

    If ($CmdPromptCurrentFolder -like "*:*") {
        Write-Host "[$CmdPromptCurrentFolder]" -NoNewline
        # -ForegroundColor White -BackgroundColor DarkGray
    }
    else {
        Write-Host "[.\$CmdPromptCurrentFolder\]" -NoNewline
        # -ForegroundColor White -BackgroundColor DarkGray
    }

    Write-Host " $date " # -ForegroundColor White
    Write-Host "[$elapsedTime] " -NoNewline -ForegroundColor Green
    return "> "
} #end prompt function

# Set Alias
Set-Alias which where.exe
