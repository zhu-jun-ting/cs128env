docker stop cs128env
docker rm cs128env
$PSScriptRoot 
$SETUP_WIN= $PSScriptRoot+"\setup-win.ps1"
&$SETUP_WIN