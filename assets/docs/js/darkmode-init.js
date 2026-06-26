const globalDark = window.matchMedia && window.matchMedia('(prefers-color-scheme: dark)').matches;
const localMode = localStorage.getItem('theme');

if (localMode === 'dark') {
  document.documentElement.setAttribute('data-dark-mode', '');
} else if (localMode === 'light') {
  document.documentElement.removeAttribute('data-dark-mode');
} else if (globalDark) {
  document.documentElement.setAttribute('data-dark-mode', '');
} else {
  document.documentElement.removeAttribute('data-dark-mode');
}
