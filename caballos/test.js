
const btn = document.querySelector('.btn button');
const nav_ul = document.querySelector('.navbar .links ul');

btn.addEventListener('click', () => {

    nav_ul.classList.toggle('active');

})
