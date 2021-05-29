#pragma once

enum EVENTS {
	evNothing = 0,
	evMessage = 100
};

enum COMMANDS {
	cmMake = 1,
	cmAdd = 2,
	cmDel = 3,
	cmShow = 4,
	cmName = 5,
	cmQuit = 6
};

struct TEvent {
	int what; 
	union {
		int command;
		struct {
			int message;
			int param;
		};
	};
};
