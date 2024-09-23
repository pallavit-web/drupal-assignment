(function ($) {
  $(document).ready(function () {
    
    $('#ajax-form').click(function (event) { 
      var name = $("#edit-name").val();
      var email = $("#edit-email").val();
     
      if (name == '' && name.length < 3) {
        event.preventDefault();
        $('#edit-name').after('<div class="error-message" style="color:red;">This field is required and  should be greater than 3</div>');
      } else if (email == '') {
        event.preventDefault();
        $('#edit-email').after('<div class="error-message" style="color:red;"> Please enter a valid email address </div>');
      } else {
        $.ajax({
          type: "POST",
          url: "http://localhost/demo/?q=submit_ajax_data",
          async: false,
          data: {
            name:name,
            email:email
          },
          success: function(response) {
            console.log('hi');
           
            $('#message').html(response.message);
          },
          error: function(error) {
            console.log('hi2222222'+error);
            // Handle the error.
            $('#message').html('An error occurred. Please try again.');
          }
        });
      }
    });
  }); 
})(jQuery);