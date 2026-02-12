//Low light switcher
document.addEventListener('DOMContentLoaded', () => {
    const mode = document.getElementById('mode');

    if (mode !== null) {
        console.log("Theme switcher initialized");

        window.matchMedia('(prefers-color-scheme: dark)').addEventListener('change', event => {
            if (event.matches) {
                localStorage.setItem('theme', 'dark');
                document.documentElement.setAttribute('data-dark-mode', '');
            } else {
                localStorage.setItem('theme', 'light');
                document.documentElement.removeAttribute('data-dark-mode');
            }
        });

        mode.addEventListener('click', (e) => {
            e.preventDefault(); // Prevent any default button behavior
            document.documentElement.toggleAttribute('data-dark-mode');

            const isDark = document.documentElement.hasAttribute('data-dark-mode');
            localStorage.setItem('theme', isDark ? 'dark' : 'light');
            console.log("Theme switched to:", isDark ? 'dark' : 'light');
        });

        // Initialize state
        if (localStorage.getItem('theme') === 'dark') {
            document.documentElement.setAttribute('data-dark-mode', '');
        } else if (localStorage.getItem('theme') === 'light') {
            document.documentElement.removeAttribute('data-dark-mode');
        } else {
            // Default to dark if no preference (as requested previously)
            // Check if darkmode-init.js already handled this, but ensuring consistency here
            if (!localStorage.getItem('theme')) {
                document.documentElement.setAttribute('data-dark-mode', '');
            }
        }
    } else {
        console.error("Theme switcher button #mode not found");
    }
});