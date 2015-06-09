## Wczytywanie C++
ai = local_import("elkostatki_ai", reload = True);

## Główna otoczka do gry
def index():
	return dict()

# Ustaw nową grę, wygeneruj i ustaw do sesji plansze
def new_game():
	player_field = ai.generate_field()
	cpu_field = ai.generate_field()
	session.player_field = list(player_field)
	session.cpu_field = list(cpu_field)
	return dict(player_field=player_field, cpu_field=cpu_field)
	
## Odczytaj już istniejące plansze
def continue_game():
	return dict(player_field=session.player_field, cpu_field=session.cpu_field)

## Pobierz pole z grą
def get_field():
	#jeśli wymusimy nową planszę, (wartością GET) 
	force_new_game = request.vars["force_new_game"];
	#jeśli oddajemy strzał gracza
	shoot_field = request.vars["shoot"];
	game = dict()
	if not session.player_field or not session.cpu_field or force_new_game == "true":
		#jeśli sesja jest pusta. generujemy nową
		game = new_game()
	else:
		if shoot_field != None:
			#gracz strzela
			shoot_field = int(shoot_field)
			if shoot_field < 0 or shoot_field > 99:
				return "Niepoprawne Dane!"
			field = session.cpu_field[shoot_field]
			if field=="w":
				print("pudło")
				session.cpu_field[shoot_field] = "p"
			if field=="s": 
				print("trafiony")
				session.cpu_field[shoot_field] = "t"
			#komputer strzela
			#odwołanie do C++
			cpu_shoot = ai.shoot("".join(session.player_field))
			field = session.player_field[cpu_shoot]
			if field=="w":
				session.player_field[cpu_shoot] = "p"
			if field=="s": 
				session.player_field[cpu_shoot] = "t"
			#sprawdzamy, kto wygrał
			if session.player_field.count("s") == 0 and session.cpu_field.find("s") == -1:
				return "<h1 class='win'>Remis!</h1>"
			elif session.player_field.count("s") == 0:
				return "<h1 class='win'>Komputer wygrał!</h1>"
			elif session.cpu_field.count("s") == 0:
				return "<h1 class='win'>Gracz wygrał!</h1>"
		game = continue_game()
	return game

	
