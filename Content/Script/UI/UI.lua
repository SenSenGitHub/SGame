---@class UI
---@field UIConfig table UI配置信息
---@field UIStack table 进栈UI
---@field UIAll table 所有的ＵＩ
---@field UIConfig.sName string UI的名字
UI={UIConfig={},UIStack ={},UIAll = {}}

---当前UI下标
UI.Index=0

---从UI配置表加载信息
function UI.LoadConfig()
    local config= UE4.TMap(UE4.FString,UE4.FUIConfig)
    UE4.UBPFunLib.LoadUIConfig(config)
    local key=config:Keys()
    for i=1,key:Length() do
        local sName=string.lower(key:Get(i))
        UI.UIConfig[sName]=config:Find(key:Get(i))
    end
    print("UI配置表读取成功") 
end

---获取到栈顶UI
function UI.GetTop()
    if UI.UIStack[UI.Index] then
        return UI.UIStack[UI.Index]
    end
        return nil
end

---出栈
function UI.Pop()
    ---1/获取到栈顶的UI  把他关闭  2.打开下层的UI 3。去把标记的一些变量改正   
    ---特殊情况 当前只有一个UI  判断UI栈的长度是不是等于1
    if UI.Index > 1 then
        UI.GetTop():DoClose()
        UI.UIAll[UI.GetTop().sName]=nil
        UI.UIStack[UI.Index] =nil
        UI.Index=UI.Index-1
        UI.GetTop():DoOpen()
    end
end

---入栈
---@param Widget Widget 入栈UI
function UI.Push(Widget)
    if UI.GetTop() ~= nil or UI.Index==0 then
        if UI.GetTop() ~= nil then
            UI.GetTop():RemoveFromParent()
        end
        if Widget then
            Widget:DoOpne()
        end
        UI.Index= UI.Index +1
        UI.UIStack[UI.Index]=Widget
        UI.UIAll[Widget.sName]=Widget
    end
end

---打开UI
---@param Name string 打开UI的主键
function UI.OpenUI(Name,...)
    Err("Name")
    if UI.UIAll[Name] ~= nil then
        Err("UI已经打开")
        return
    end

    --设置UI路径
    local WidgetClass=UI.UIConfig[Name].WidgetClass.AssetPathName
    --UI层级
    local WidgetLevel=UI.UIConfig[Name].Level
    --判断是不是关闭其他所有的UI
    local IsCloseAll=UI.UIConfig[Name].IsCloseAll
    --判断是否入栈
    local IsStack=UI.UIConfig[Name].IsStack
    local Ins= GetGameInstance()
    local Widget=UE.UWidgetBlueprintLibrary.Create(...,UE.UClass.Load(WidgetClass))
    Widget.sName=Name
    if IsCloseAll then
        --关闭其他
    end
    if IsStack then
        UI.Push(Widget)
    end
end

---关闭UI
---@param Name string 关闭UI的主键
function UI.CloseUI(Name)
    local IsStack = UI.UIConfigp[Name].IsStack
    if IsStack then
        UI.Pop()
        return
    end
    local Widget = UI.UIAll[Name]
    UI.UIAll[Name] = nil
    Widget:DoClose()
end

---关闭所有UI
function UI.CloseAllUI()
    print("关闭所有UI")
    for key, value in pairs(UI.UIAll) do
        if value then
            value:DoClose()
        end
    end
end

---获取已经打开的UI
---@param Name string 关闭UI的主键
function UI.GetUIByName(Name)
    if UI.UIAll[Name] then
        return UI.UIAll[Name] 
    end
    return nil
end

UI.LoadConfig()