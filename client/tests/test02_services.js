/// @file test02_services.js
/// @brief client unit tests, check the service calling

var injector = angular.injector(['ng', 'myApp']);

module( "test02_services", {
    setup: function() {
	    this.$scope = injector.get('$rootScope').$new();
		var srv = injector.get('srvInfo')
		srv.baseURL = "http://127.0.0.1:50008/"; //port for srv.py mock service
    },
    teardown: function() { }
});

function functionResponseCheck() {
    ok( 1 == "1", "function response check");
}

asyncTest( "service getVersion", function() {
    expect( 1 );
	var srv = injector.get('srvInfo');
	srv.getVersion(functionResponseCheck);
    setTimeout(
		function() {
			start();
		},
		100);
});

asyncTest( "service getCurrent", function() {
    expect( 1 );
	var srv = injector.get('srvInfo');
	srv.getCurrent(functionResponseCheck);
    setTimeout(
		function() {
			start();
		},
		100);
});

asyncTest( "service getCppNumber", function() {
    expect( 1 );
	var srv = injector.get('srvInfo');
	srv.getCppNumber(functionResponseCheck);
    setTimeout(
		function() {
			start();
		},
		100);
});



