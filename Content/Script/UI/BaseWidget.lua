local SGame = Class()

function SGame:DoOpne(...)
    print("打开UI"..self.sName)
    self:AddToViewport()
    UE4.UBPFunLib.AddToRoot(self)

    self:OnOpen(...)
end

function SGame:DoClose(...)
    print("关闭"..self.sName)
    self:OnClose(...)
    UE4.UBPFunLib.RemoveToRoot(self)
    self:RemoveFromViewport()
end

function SGame:OnOpen(...)
    -- body
end

function SGame:OnClose(...)
    -- body
end

return SGame