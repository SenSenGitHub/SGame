---@param Text string 提示内容
function Err(Text)
    print(Text)
end
function BtnAddFun(Btn,fun)
    local pOuter=UE4.UBPFunLib.GetWidgetOuter(Btn)
    if Btn  then
        Btn.OnClicked:Add(pOuter,fun)
    end
end

function GetGameInstance()
    if UE4.USGameGameInstance.GET() ~= nil then
        return UE4.USGameGameInstance.GET()
    end
    return nil
end