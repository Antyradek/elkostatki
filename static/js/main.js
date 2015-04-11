//Załaduj grę i umieść w elemencie field
function load_game(src)
{
	src = "elkostatki/default/" + src;
	$("#field").html("<p>Ładowanie...</p>");
	$.get(src, function(data, status)
	{
		$("#field").html(data);
	});
}

$(document).ready(function()
{
	load_game("get_field");
	$("#new_game_button").click(function()
	{
		load_game("get_field?force_new_game=true");
	});
});
