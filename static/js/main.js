//Załaduj grę i umieść w elemencie field
function load_game(src)
{
	src = "elkostatki/default/" + src;
	//$("#loading").html("Ładowanie...");
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

function shoot(field)
{
	load_game("get_field?shoot=" + field);
}
