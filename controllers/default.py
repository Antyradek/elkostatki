import subprocess
ai = local_import("elkostatki_ai", reload = True);

## Główna otoczka do gry
def index():
	return dict()

#ustaw nową grę, wygeneruj i ustaw do sesji
def new_game():
	field = ai.generate_field();
	session.game = field
	return dict(txt=field)
	
def continue_game():
	return dict(txt=session.game)

## Pobierz pole z grą
def get_field():
	force_new_game = request.vars["force_new_game"];
	game = dict()
	if not session.game or force_new_game == "true":
		#nowy użytkownik
		game = new_game()
	else:
		game = continue_game()
	return game

	
