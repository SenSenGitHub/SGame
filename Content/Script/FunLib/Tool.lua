---@param Text string 提示内容
function Err(Text)
    print(Text)
end

---按钮添加函数
function BtnAddFun(Btn,fun)
    local pOuter=UE4.UBPFunLib.GetWidgetOuter(Btn)
    if Btn  then
        Btn.OnClicked:Add(pOuter,fun)
    end
end

---获取到游戏实例
function GetGameInstance()
    if UE4.USGameGameInstance.GET() ~= nil then
        return UE4.USGameGameInstance.GET()
    end
    return nil
end

---生成Obj
---@param outer Object 生成着
---@param ClassPatn string 路径
function NewUE4Object(outer,ClassPatn)
    return _G.NewObject(UE4.UClass.Load(ClassPatn),outer)
end