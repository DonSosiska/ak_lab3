.PHONY: build
build:
	g++ ./hw3.cpp -o app

default_goal: build def 

.PHONY: def
def:
	./app -l -h -v --value=1 -f1

.PHONY: run
run:
	./app -l


.DEFAULT_GOAL:=default_goal
