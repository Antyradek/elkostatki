ai = local_import("elkostatki_ai", reload = True);

## Główna otoczka do gry
def index():
	return dict()

#ustaw nową grę, wygeneruj i ustaw do sesji
def new_game():
	player_field = ai.generate_field()
	cpu_field = ai.generate_field()
	session.player_field = list(player_field)
	session.cpu_field = list(cpu_field)
	return dict(player_field=player_field, cpu_field=cpu_field)
	
def continue_game():
	return dict(player_field=session.player_field, cpu_field=session.cpu_field)

## Pobierz pole z grą
def get_field():
	#jeśli wymusimy nową planszę 
	force_new_game = request.vars["force_new_game"];
	#jeśli oddajemy strzał przy okazji
	shoot_field = request.vars["shoot"];
	game = dict()
	if not session.player_field or not session.cpu_field or force_new_game == "true":
		#nowy użytkownik
		game = new_game()
	else:
		if shoot_field != None:
			#my strzelamy
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
			#trzeba przerobić na stringa. Nie wiem. Może przyjmuje tablice, albo listy?
			cpu_shoot = ai.shoot("".join(session.player_field))
			field = session.player_field[cpu_shoot]
			if field=="w":
				session.player_field[cpu_shoot] = "p"
			if field=="s": 
				session.player_field[cpu_shoot] = "t"
			#sprawdzamy, kto wygrał, to zwracanie stringa zamiast strony trzeba będzie jeszcze dopracować
			if session.player_field.count("s") == 0 and session.cpu_field.find("s") == -1:
				return "Remis!"
			elif session.player_field.count("s") == 0:
				return "Komputer wygrał!"
			elif session.cpu_field.count("s") == 0:
				return "Gracz wygrał!"
		game = continue_game()
	return game

	
