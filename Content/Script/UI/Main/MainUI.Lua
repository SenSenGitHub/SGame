local SGame=Class("UI.BaseWidget")

local SaveGameObj

function SGame:OnOpen(...)
    BtnAddFun(self.Btn,function()
        SaveGameObj=SpawnSaveGameObj()
        SaveGameObj.Test="123"
    end)
    BtnAddFun(self.Btn_1,function()
        local var = SaveGameToSlot(SaveGameObj,"test",1)
        print(var)
    end)
    BtnAddFun(self.Btn_2,function()
        local var = DoesSaveGameExist("test",1)
        print(var)
    end)
    BtnAddFun(self.Btn_3,function()
        local var = LoadGameFromSlot("test",1)
        print(var.Test)
    end)
end
return SGame