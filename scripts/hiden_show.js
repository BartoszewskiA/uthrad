$(document).ready(function () {

    // $(".hiden_selection").slideToggle();

    $("#button_hide").click(function () {
        $(".menu_przedmioty").slideToggle();
    });

    $(".read_more .switcher").click(function () {

        $(this).closest(".read_more").find(".hiden_selection").slideToggle();

        if ($(this).html() == "Zwiń") {
            $(this).html("Rozwiń")
        } else {
            $(this).html("Zwiń")
        };

        if ($(this).closest(".read_more").find(".visible_selection").hasClass("winieta")) {
            $(this).closest(".read_more").find(".visible_selection").removeClass("winieta")
        } else {
            $(this).closest(".read_more").find(".visible_selection").addClass("winieta")
        }
    });
})