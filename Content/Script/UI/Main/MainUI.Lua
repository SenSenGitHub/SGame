local SGame=Class("UI.BaseWidget")
function SGame:OnOpen(...)
    BtnAddFun(self.Btn,function()
        UI.CloseAllUI()
    end)
end
return SGame