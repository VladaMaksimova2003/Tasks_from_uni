function showTime() {
   let days = [
      'Воскресенье',
      'Понедельник',
      'Вторник',
      'Среда',
      'Четверг',
      'Пятница',
      'Суббота'
   ];
   let today = new Date();
   let hour = today.getHours() - (today.getHours() >= 12 ? 12 : 0);
   let minute = today.getMinutes();
   let second = today.getSeconds();
   let period = today.getHours() >= 12 ? 'PM' : 'AM';
   if (minute < 10) minute = "0" + minute;
   if (second < 10) second = "0" + second;
   console.log('Сегодня: ' + days[today.getDay()] + '\nТекущее время: ' + hour + period + ' : ' + minute + ' : ' + second);
}
function validateForm() {
   let form_object = document.forms.firstform;
   let number1 = +form_object.elements.number1.value;
   let number2 = +form_object.elements.number2.value;
   let number3 = +form_object.elements.number3.value;
   if (number1 == "" || number2 == "" || number3 == "") {
      alert('Вы должны ввести значение!');
      return false;
   } else if (number1 < 0 || number2 < 0 || number3 < 0) {
      alert('Значение должно быть положительным');
      return false;
   } else if (number1 + number2 < number3 || number3 + number2 < number1 || number1 + number3 < number2) {
      confirm('Такого треугольника не существует \nХотите проверить данные?');
      return false;
   } else {
      let p = (number1 + number2 + number3) * 0.5;
      let s = Math.sqrt(p * (p - number1) * (p - number2) * (p - number3));
      alert('Такой треугольник существует \nЕго площадь ' + s);
      return true;
   }
}
function searchNumber() {
   let number = +prompt('Введите любое число для проверки на совершенство');
   let sum = 0;
   let i = 1;
   for (let limit = number >> 1; i <= limit; ++i) {
      if (!(number % i)) sum += i;
   }
   if (sum == number) { alert('Введённое число является совершенным'); return true; }
   else alert('Введённое число не является совершенным'); return false;
}
function searchGrade() {
   let school = {
      pupils: [
         { 'name': "Ида", score: 37, grade: "6" },
         { 'name': "Лена", score: 46, grade: "4" },
         { 'name': "Артур", score: 70, grade: "6" },
         { 'name': "Платон", score: 88, grade: "1" }
      ]
   };
   for (let i = 0; i < school.pupils.length; i++) {
      if (school.pupils[i].score < 60) school.pupils[i].grade = "Незачет";
      else if (school.pupils[i].score < 70) school.pupils[i].grade = "3";
      else if (school.pupils[i].score < 90) school.pupils[i].grade = "4";
      else school.pupils[i].grade = "5";
   }
   var table = document.createElement("table");
   var tbody = document.createElement("tbody");
   table.appendChild(tbody);
   for (var i = 0; i < school.pupils.length; i++) {
      var tr = document.createElement('tr');
      for (var j = 0; j < 1; j++) {
         var td = document.createElement('td');
         td.innerHTML = school.pupils[i].name;
         tr.appendChild(td);
      }
      for (var j = 0; j < 1; j++) {
         var td = document.createElement('td');
         td.innerHTML = school.pupils[i].score;
         tr.appendChild(td);
      }
      for (var j = 0; j < 1; j++) {
         var td = document.createElement('td');
         td.innerHTML = school.pupils[i].grade;
         tr.appendChild(td);
      }
      tbody.appendChild(tr);
   }
   document.getElementById("myTable").appendChild(table);
}
showTime();
searchNumber();