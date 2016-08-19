[CmdletBinding()]
param(
    [Parameter(Mandatory=$True)]
    [string]$Configuration,
    
    [Parameter()]
    [string]$LibDir = "..\lib",
    
    [Parameter()]
    [string]$IncludeDir = "..\include"
)

$ErrorActionPreference = "Stop"

if (!(Test-Path $LibDir)) {
    mkdir $LibDir | Out-Null
}

if (!(Test-Path $IncludeDir)) {
    mkdir $IncludeDir | Out-Null
}

cp "..\$Configuration\CSharpLibraryBridge.dll" $LibDir
cp "..\$Configuration\CSharpLibraryBridge.lib" $LibDir
cp ".\ExampleObj.h" $IncludeDir