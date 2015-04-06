import subprocess
def index():
	game = dict()
	if not session.game:
		#nowy użytkownik
		game = new_game()
	else:
		game = continue_game()
	return game

#ustaw nową grę, wygeneruj i ustaw do sesji
def new_game():
	field = subprocess.Popen("applications/elkostatki/modules/generator -g", shell=True, stdout=subprocess.PIPE).stdout.read()
	session.game = field
	return dict(txt=field)
	
def continue_game():
	return dict(txt=session.game)
