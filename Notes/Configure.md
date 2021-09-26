### Bash

<details>

<summary> .bashrc </summary>

```bash
################################################################################

# Last Command Time

function t_now {
    date +%s%3N
}

function t_start {
    t_start=${t_start:-$(t_now)}
}

function t_stop {
    local d_ms=$(($(t_now) - $t_start))
    local d_s=$((d_ms / 1000))
    local ms=$((d_ms % 1000))
    local s=$((d_s % 60))
    local m=$(((d_s / 60) % 60))
    local h=$((d_s / 3600))
    if ((h > 0)); then
        t_show=${h}h${m}m
    elif ((m > 0)); then
        t_show=${m}m${s}s
    elif ((s >= 10)); then
        t_show=${s}.$((ms / 100))s
    elif ((s > 0)); then
        t_show=${s}.$((ms / 10))s
    else
        t_show=${ms}ms
    fi
    unset t_start
}

set_prompt () {
    t_stop
}

trap 't_start' DEBUG
PROMPT_COMMAND='set_prompt'

CPS1='\n[${t_show}] > '

################################################################################

# Fortune

echo
echo
fortune-zh
echo
echo

################################################################################

# VcXsrv

export DISPLAY=$(awk '/nameserver / {print $2; exit}' /etc/resolv.conf 2>/dev/null):0 # in WSL 2
export LIBGL_ALWAYS_INDIRECT=0

################################################################################
```

</details>

### PowerShell

<details>

<summary> profile.ps1 </summary>

```powershell

#region conda initialize
# !! Contents within this block are managed by 'conda init' !!
(& "D:\Anaconda\Scripts\conda.exe" "shell.powershell" "hook") | Out-String | Invoke-Expression
#endregion

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

```

</details>


