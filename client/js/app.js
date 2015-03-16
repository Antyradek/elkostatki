/// @file app.js
/// @brief main client module, AngularJS application with routing

angular.module('myApp', ['ngRoute', 'pascalprecht.translate', 'myAppControllers', 'myAppServices'] )
    .config(['$routeProvider', '$translateProvider',
             function($routeProvider, $translateProvider) {
                 $routeProvider.when('/about', {
                     templateUrl: 'views/about.html',
                 });
                 $routeProvider.otherwise( {
                     redirectTo: '/about'
                 });
                 $translateProvider.useStaticFilesLoader({
                      prefix: 'lang/',
                      suffix: '.json' });
                 $translateProvider.preferredLanguage('en');
             }]);

