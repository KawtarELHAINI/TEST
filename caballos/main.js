
const questions = document.querySelectorAll('.question-answer');

questions.forEach(function(question) {
    const btn = question.querySelector('.question-btn');
    btn.addEventListener("click", function() {
        questions.forEach(function(item) {
            if (item !== question) {
                item.classList.remove("show-text");
            }
        })
        question.classList.toggle("show-text");
    })
})



/***********************   validation page contacte     *********** */

let email_input = document.getElementsByClassName("contact-input");

for (let i = 0; i <= email_input.length; i++) {
  email_input[i].addEventListener("invalid", () => {
    input_error(email_input[i]);
  });

  email_input[i].addEventListener("input", () => {
    input_error(email_input[i]);
  });
}
console.log(email_input[i]);

function input_error(x) {
  if (x.validity.valueMissing) {
    x.setCustomValidity("Vous n'avez saisi aucune donnée dans ce champ.");
  } else if (x.validity.typeMismatch) {
    x.setCustomValidity("Données invalides");
  } else {
    x.setCustomValidity("");
    return true;
  }
  document.getElementById("error_message").innerText = x.validationMessage;
}