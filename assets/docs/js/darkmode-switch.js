document.addEventListener('DOMContentLoaded', () => {
    const mode = document.getElementById('mode');
    if (!mode) return;

    const applyTheme = (isDark) => {
        if (isDark) {
            document.documentElement.setAttribute('data-dark-mode', '');
        } else {
            document.documentElement.removeAttribute('data-dark-mode');
        }
    };

    const stored = localStorage.getItem('theme');
    if (stored === 'dark') {
        applyTheme(true);
    } else if (stored === 'light') {
        applyTheme(false);
    }

    window.matchMedia('(prefers-color-scheme: dark)').addEventListener('change', (event) => {
        if (localStorage.getItem('theme')) return;
        applyTheme(event.matches);
    });

    mode.addEventListener('click', (e) => {
        e.preventDefault();
        const isDark = !document.documentElement.hasAttribute('data-dark-mode');
        applyTheme(isDark);
        localStorage.setItem('theme', isDark ? 'dark' : 'light');
    });
});
