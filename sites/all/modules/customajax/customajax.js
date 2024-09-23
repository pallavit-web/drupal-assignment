(function ($) {
    $(document).ready(function () {
      $('#mymodule-ajax-form').submit(function (event) {
        var name = $("#edit-name").val();
        if (name == '') {
          event.preventDefault();
          $('#edit-name').after('<div class="error-message" style="color:red;">This field is required and  should be greater than 3</div>');
        }
      });
    });
  })(jQuery);
  