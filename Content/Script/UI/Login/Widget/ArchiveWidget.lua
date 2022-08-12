

local SGame = Class("UI.BaseWidget")


function SGame:OnOpen()
    BtnAddFun(self.Confirm,function ()
        ---选中存档 self.SelectArchive=
    end)
    BtnAddFun(self.Cancel,function()
        UI.CloseUI("ArchiveWidget")
    end)
end

return SGame