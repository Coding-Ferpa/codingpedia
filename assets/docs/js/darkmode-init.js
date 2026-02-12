const globalDark = window.matchMedia && window.matchMedia('(prefers-color-scheme: dark)').matches;
const localMode = localStorage.getItem('theme');

if (localMode === null) {
  localStorage.setItem('theme', 'dark');
  document.documentElement.setAttribute('data-dark-mode', '');
} else if (localMode === 'dark') {
  document.documentElement.setAttribute('data-dark-mode', '');
}