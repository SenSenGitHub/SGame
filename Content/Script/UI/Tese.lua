require "require"
local SGame=Class()



function SGame:ReceiveBeginPlay()
    GetGameInstance()
    UI.OpenUI("main",self)
end

return SGame