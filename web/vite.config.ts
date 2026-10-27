import { defineConfig } from 'vite';
import react from '@vitejs/plugin-react';
import { VitePWA } from 'vite-plugin-pwa';

export default defineConfig({
  plugins: [
    react(),
    VitePWA({
      registerType: 'autoUpdate',
      includeAssets: ['fonts/*.ttf'],
      manifest: {
        name: 'BitLife Web',
        short_name: 'BitLife',
        description: 'Life simulator — web port',
        theme_color: '#12161c',
        background_color: '#12161c',
        display: 'standalone',
        orientation: 'portrait',
        start_url: '/',
        icons: [
          { src: 'icons/192.png', sizes: '192x192', type: 'image/png' },
          { src: 'icons/512.png', sizes: '512x512', type: 'image/png' },
          { src: 'icons/512.png', sizes: '512x512', type: 'image/png', purpose: 'maskable' },
        ],
      },
      workbox: {
        // the whole CSV corpus is the game content and never changes between
        // builds of the same game version — precache it once, serve offline.
        globPatterns: ['**/*.{js,css,html,ttf,png,svg,wav,json,webmanifest}', 'data/*.csv'],
        maximumFileSizeToCacheInBytes: 20 * 1024 * 1024,
        runtimeCaching: [
          {
            urlPattern: /\/data\/.*\.csv$/,
            handler: 'CacheFirst',
            options: {
              cacheName: 'bitlife-csv',
              expiration: { maxEntries: 1200, maxAgeSeconds: 60 * 60 * 24 * 365 },
            },
          },
        ],
      },
    }),
  ],
  build: { target: 'es2022', sourcemap: true },
});
