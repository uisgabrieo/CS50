document.addEventListener("DOMContentLoaded", function(event) {
    function visibility() {
        let info = document.querySelector('.animal-info');
        let img = document.querySelector('img');
        let name = document.querySelector('.name-animal');

        if (info.style.visibility === 'hidden' || info.style.visibility === '') {
            name.style.visibility = 'visible';
            info.style.visibility = 'visible';
            img.classList.remove('img-animal-start')
            img.classList.add('img-animal-click')
        } else {
            info.style.visibility = 'hidden';
            name.style.visibility = 'hidden';
            img.classList.remove('img-animal-click')
            img.classList.add('img-animal-start')
        }
    }

    window.visibility = visibility;
});
