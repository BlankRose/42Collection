-- This program will print its own source when run.
Colleen = "-- This program will print its own source when run.%1Colleen = %2%3%2%1%1function print(s)%1	io.write(s)%1end%1%1function main()%1	-- This program will print its own source when run.%1	print(Colleen:gsub(%2%%%%.%2, {[%2%%%%%2] = '%%', [%2%%1%2] = string.char(10), [%2%%2%2] = '%2', [%2%%3%2] = Colleen}))%1end%1%1main()%1"

function print(s)
	io.write(s)
end

function main()
	-- This program will print its own source when run.
	print(Colleen:gsub("%%.", {["%%"] = '%', ["%1"] = string.char(10), ["%2"] = '"', ["%3"] = Colleen}))
end

main()
