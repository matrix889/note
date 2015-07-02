-module(loop).
-export([start/0, do/0]).

start() -> spawn(loop, do, []).

do() -> 
	receive
		{Client, fuck} ->
			io:format("what the fuck~n");
		{Client, what} ->
			io:format("fuck your sister~n")
	end,
	do().