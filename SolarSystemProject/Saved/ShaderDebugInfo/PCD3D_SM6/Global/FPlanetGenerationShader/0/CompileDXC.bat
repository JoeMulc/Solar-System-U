@ECHO OFF
SET DXC="D:\Epic Games\UE_5.5\Engine\Binaries\ThirdParty\ShaderConductor\Win64\dxc.exe"
IF NOT EXIST %DXC% (
	ECHO Couldn't find dxc.exe under "D:\Epic Games\UE_5.5\Engine\Binaries\ThirdParty\ShaderConductor\Win64"
	GOTO :END
)
%DXC% -HV 2021 -Zpr -O3 -auto-binding-space 0 -Wno-parentheses-equality -disable-lifetime-markers -T cs_6_6 -E PlanetGenerationShader -Fc PlanetGenerationShader.d3dasm -Fo PlanetGenerationShader.dxil PlanetGenerationShader.usf
:END
PAUSE
