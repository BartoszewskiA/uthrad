// (function ($) {

$(document).ready(function () {

    $("#wyklady").hover(function () {
        $("#header").toggleClass('newBackground01');
        // $(".logo").toggleClass('filtr_logo');
    })

    $("#praktyki").hover(function () {
        $("#header").toggleClass('newBackground02');
    })

    $("#aktualnosci").hover(function () {
        $("#header").toggleClass('newBackground01');
    })

    $("#o_mnie").hover(function () {
        $("#header").toggleClass('newBackground04');
    })


})

// })(jQuery);