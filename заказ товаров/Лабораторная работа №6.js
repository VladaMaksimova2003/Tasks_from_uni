
var submit = document.querySelector('#submit');
submit.addEventListener('click', function () {
   var wrapper = document.querySelector("#table");
   var form = wrapper.getElementsByTagName("form")[0];
   var table = wrapper.getElementsByTagName("table")[0];

   form.onsubmit = function (ev) {
      ev.preventDefault();// Отменяем переход по ссылке
      var tr = document.createElement("tr"), td;
      
      var td3 = document.createElement("td");
      var checkbox = document.createElement('input');
      checkbox.type = "checkbox";
      checkbox.name = "btnradio";
      checkbox.classList.add("form-check-input");

      for (let i = 0; i < 2; i++) {
         td = document.createElement("td");
         td.innerHTML = this.elements[i].value;
         tr.append(td);
      }
      let but = document.createElement("button");
      but.classList.add("btn");
      but.classList.add("btn-secondary");
      but.classList.add("btn-sm");
      let buttext = document.createTextNode("Удалить");
      but.append(buttext);
      but.onclick = function () {
         tr.parentNode.removeChild(tr);
      }
      td3.append(but);
      td3.append(checkbox);
      tr.append(td3);
      table.append(tr);



      var elements = table.querySelectorAll("td");
      function changeColor() {
         this.style.backgroundColor = "#CD5C5C";
      }
      function changeColor1() {
         this.style.backgroundColor = "#fff";
      }
      for (let i = 0; i < elements.length; ++i) {
         elements[i].addEventListener('mouseover', changeColor);
         elements[i].addEventListener('mouseout', changeColor1);

      }
   }


});
var button = document.querySelector("#button");
button.addEventListener("click", function () {
   let sum = 0;
   let class_check = document.getElementsByName("btnradio");
   for (let i = 0; i < class_check.length; ++i) {
      if (class_check[i].checked){
   let table = document.querySelector("#table");
   let tds = table.querySelectorAll("td:nth-child(2)");
      sum += Number(tds[i].innerHTML);
}
}

   total.innerHTML = sum;
});





