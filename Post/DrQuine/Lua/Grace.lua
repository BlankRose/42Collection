-- This program will print its own source when run.
local Colleen = "-- This program will print its own source when run.%1local Colleen = %q%1%1function Grace()%1\9local file = io.open(%2Grace_kid.lua%2, %2w%2)%1\9if file == nil then return end%1%1\9local str = Colleen:gsub(%2%%%%.%2, {[%2%%1%2] = string.char(10), [%2%%2%2] = '%2'})%1\9file:write(str:format(Colleen))%1\9file:close()%1end%1%1Grace()"

function Grace()
	local file = io.open("Grace_kid.lua", "w")
	if file == nil then return end

	local str = Colleen:gsub("%%.", {["%1"] = string.char(10), ["%2"] = '"'})
	file:write(str:format(Colleen))
	file:close()
end

Grace()