



---创建游戏保存实例
function SpawnSaveGameObj()
    return NewUE4Object(GetGameInstance(),"/Game/SaveGame/BP_SGameSaveGame.BP_SGameSaveGame_C")
end

---保存游戏
---@param SaveGameClass object 保存游戏实例
---@param SlotName string 保存名称
---@param UserIndex int 保存序号
---@return boolean 是否保存成功
function SaveGameToSlot(SaveGameClass,SlotName,UserIndex)
    return UE.UGameplayStatics.SaveGameToSlot(SaveGameClass,SlotName,UserIndex)
end

---查看存档是否存在
---@param SlotName string 插槽的名称
---@param UserIndex int 插槽的序号
---@return boolean 是否存在
function DoesSaveGameExist(SlotName,UserIndex)
    return UE.UGameplayStatics.DoesSaveGameExist(SlotName,UserIndex)
end

---加载存档
---@param SlotName string 插槽的名称
---@param UserIndex int 插槽的序号
---@return USaveGame 存档实例
function LoadGameFromSlot(SlotName,UserIndex)
    return UE.UGameplayStatics.LoadGameFromSlot(SlotName,UserIndex)
end

---删除存档
---@param SlotName string 插槽的名称
---@param UserIndex int 插槽的序号
---@return boolean 是否删除成功
function DeleteGameInSlot(SlotName,UserIndex)
    return UE.UGameplayStatics.DeleteGameInSlot(SlotName,UserIndex)
end