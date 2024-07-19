// Smooth scrolling for anchor links in header
document.querySelectorAll('header a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function(e) {
        e.preventDefault();

        const target = document.querySelector(this.getAttribute('href'));
        target.scrollIntoView({
            behavior: 'smooth'
        });
    });
});

// Form submission handling
document.addEventListener('DOMContentLoaded', function() {
    const contactForm = document.getElementById('contactForm');
    const responseMessage = document.getElementById('responseMessage');

    contactForm.addEventListener('submit', function(event) {
        event.preventDefault(); // Prevent the default form submission

        // Get user inputs
        const name = contactForm.elements['name'].value;
        const email = contactForm.elements['email'].value;
        const message = contactForm.elements['message'].value;

        // Example: Send data to a server (you would typically use a backend for this in a real scenario)
        // For now, just display a confirmation message
        responseMessage.innerHTML = `<p>Thank you, ${name}! Your message has been sent.</p>`;

        // Clear the form after submission (optional)
        contactForm.reset();
    });
});
