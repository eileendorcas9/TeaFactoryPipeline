-- Coroutine function to represent a tea batch
function teaBatch(id)
    -- Define the pipeline stages (a: coroutine creation + stages)
    local stages = {"Receiving", "Weighing", "Withering", "Drying", "Grading", "Packaging"}
    
    -- Loop through each stage (b: yield batch ID + stage)
    for i, stage in ipairs(stages) do
        -- Yield the batch ID and current stage so the scheduler can track progress
        coroutine.yield(id, stage)
        
        -- Quality check happens after drying (c: reprocessing logic)
        if stage == "Drying" then
            local qualityPass = math.random() > 0.3  -- 70% chance to pass
            if not qualityPass then
                -- Yield a failure message and return "reprocess"
                coroutine.yield(id, "Failed Quality Check → Reprocessing")
                return "reprocess"
            end
        end
    end
    
    -- If all stages succeed, return "done"
    return "done"
end


-- Create three batch coroutines (d: scheduling multiple batches)
local batches = {
    {id=1, co=coroutine.create(function() return teaBatch(1) end)},
    {id=2, co=coroutine.create(function() return teaBatch(2) end)},
    {id=3, co=coroutine.create(function() return teaBatch(3) end)}
}


-- Scheduler: interleaves execution of all batches
while #batches > 0 do
    -- Iterate backwards so we can safely remove finished batches
    for i = #batches, 1, -1 do
        local batch = batches[i]
        
        -- Resume the coroutine (continue from last yield)
        local status, id, stage = coroutine.resume(batch.co)
        
        -- Error handling: if resume fails, remove the batch
        if not status then
            print("Error in batch "..batch.id)
            table.remove(batches, i)
        
        -- If coroutine is dead, check its return value
        elseif coroutine.status(batch.co) == "dead" then
            if stage == "reprocess" then
                -- Restart the coroutine for reprocessing
                print("Batch "..batch.id.." failed → restarting...")
                batch.co = coroutine.create(function() return teaBatch(batch.id) end)
            else
                -- Batch completed successfully
                print("Batch "..batch.id.." completed.")
                table.remove(batches, i)
            end
        
        else
            -- Normal case: print current stage
            print("Batch "..id.." at stage: "..stage)
        end
    end
end

