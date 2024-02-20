Colleen = "Colleen = %q%1%1function Sully(x)%1\9if x <= 0 then return end%1%1\9local name = %2Sully_%2 .. x .. %2.lua%2%1\9local file = io.open(name, %2w%2)%1\9if file == nil then return end%1%1\9local str = Colleen:gsub(%2%%%%.%2, {[%2%%1%2] = string.char(10), [%2%%2%2] = '%2'})%1\9file:write(str:format(Colleen, x - 1))%1\9file:close()%1%1\9os.execute(%2lua %2 .. name)%1end%1%1Sully(%d)%1"

function Sully(x)
	if x <= 0 then return end

	local name = "Sully_" .. x .. ".lua"
	local file = io.open(name, "w")
	if file == nil then return end

	local str = Colleen:gsub("%%.", {["%1"] = string.char(10), ["%2"] = '"'})
	file:write(str:format(Colleen, x - 1))
	file:close()

	os.execute("lua " .. name)
end

Sully(5)
