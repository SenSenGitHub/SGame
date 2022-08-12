require "require"
local SGame=Class()



function SGame:ReceiveBeginPlay()
    GetGameInstance()
    UI.OpenUI("login",self)
end

return SGame