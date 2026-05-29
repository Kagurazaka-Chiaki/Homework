-- Minimal long-term Neovim config
-- Target: C/C++, Python, Shell, Lua

vim.g.mapleader = " "
vim.g.maplocalleader = " "

-- =========================
-- Basic editor behavior
-- =========================
vim.opt.number = true
vim.opt.relativenumber = true
vim.opt.mouse = "a"
vim.opt.termguicolors = true
vim.opt.background = "dark"
vim.opt.signcolumn = "yes"
vim.opt.updatetime = 250
vim.opt.timeoutlen = 400

vim.opt.expandtab = true
vim.opt.shiftwidth = 4
vim.opt.tabstop = 4
vim.opt.smartindent = true

vim.opt.ignorecase = true
vim.opt.smartcase = true

vim.opt.splitright = true
vim.opt.splitbelow = true

vim.opt.completeopt = { "menuone", "noselect", "popup" }

vim.opt.list = true
vim.opt.listchars = {
  space = "·",
  tab = "→ ",
  trail = "·",
  nbsp = "␣",
}

local set_whitespace_highlight = function()
  local whitespace = { fg = "#202020" }
  vim.api.nvim_set_hl(0, "Whitespace", whitespace)
  vim.api.nvim_set_hl(0, "SpecialKey", whitespace)
end

vim.api.nvim_create_autocmd("ColorScheme", {
  callback = set_whitespace_highlight,
})

-- Windows clipboard / WSL clipboard may need extra setup.
vim.opt.clipboard = "unnamedplus"

-- =========================
-- Bootstrap lazy.nvim
-- =========================
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"

if not vim.uv.fs_stat(lazypath) then
  vim.fn.system({
    "git",
    "clone",
    "--filter=blob:none",
    "https://github.com/folke/lazy.nvim.git",
    "--branch=stable",
    lazypath,
  })
end

vim.opt.rtp:prepend(lazypath)

-- =========================
-- Plugins
-- =========================
require("lazy").setup({
  {
    "Mofiqul/vscode.nvim",
    lazy = false,
    priority = 1000,
    config = function()
      require("vscode").setup({
        style = "dark",
        transparent = true,
        italic_comments = true,
        disable_nvimtree_bg = true,
      })

      vim.cmd.colorscheme("vscode")
    end,
  },

  {
    "nvim-treesitter/nvim-treesitter",
    branch = "master",
    build = ":TSUpdate",
    config = function()
      require("nvim-treesitter.configs").setup({
        ensure_installed = {
          "c",
          "cpp",
          "python",
          "bash",
          "lua",
        },
        highlight = {
          enable = true,
          additional_vim_regex_highlighting = false,
        },
        indent = {
          enable = true,
        },
      })
    end,
  },

  {
    "neovim/nvim-lspconfig",
  },

  {
    "saghen/blink.cmp",
    version = "1.*",
    dependencies = { "rafamadriz/friendly-snippets" },
    opts = {
      keymap = {
        preset = "super-tab",
        ["<CR>"] = { "select_and_accept", "fallback" },
      },
      appearance = {
        nerd_font_variant = "mono",
      },
      completion = {
        menu = {
          auto_show = true,
        },
        documentation = {
          auto_show = true,
          auto_show_delay_ms = 200,
        },
        list = {
          selection = {
            preselect = false,
            auto_insert = false,
          },
        },
      },
      signature = {
        enabled = true,
      },
      sources = {
        default = { "lsp", "path", "snippets", "buffer" },
      },
    },
    opts_extend = { "sources.default" },
  },

  {
    "stevearc/conform.nvim",
    opts = {
      formatters_by_ft = {
        c = { "clang_format" },
        cpp = { "clang_format" },
        python = { "ruff_format" },
        sh = { "shfmt" },
        bash = { "shfmt" },
        lua = { "stylua" },
      },
    },
  },

  {
    "ibhagwan/fzf-lua",
    dependencies = { "nvim-tree/nvim-web-devicons" },
    opts = {},
    keys = {
      { "<C-p>", "<cmd>FzfLua files<cr>", desc = "Find files" },
      { "<leader>fg", "<cmd>FzfLua live_grep<cr>", desc = "Live grep" },
      { "<leader>fb", "<cmd>FzfLua buffers<cr>", desc = "Buffers" },
      { "<leader>fh", "<cmd>FzfLua helptags<cr>", desc = "Help" },
    },
  },
})

set_whitespace_highlight()

-- =========================
-- LSP
-- =========================
vim.lsp.enable({
  "clangd",
  "pyright",
  "bashls",
  "lua_ls",
})

-- Lua language server: make it understand Neovim globals.
vim.lsp.config("lua_ls", {
  settings = {
    Lua = {
      diagnostics = {
        globals = { "vim" },
      },
      workspace = {
        checkThirdParty = false,
      },
    },
  },
})

-- =========================
-- LSP keymaps
-- =========================
vim.api.nvim_create_autocmd("LspAttach", {
  callback = function(event)
    local bufnr = event.buf
    local client = vim.lsp.get_client_by_id(event.data.client_id)

    if client then
      client.server_capabilities.semanticTokensProvider = nil
    end

    local map = function(mode, lhs, rhs, desc)
      vim.keymap.set(mode, lhs, rhs, {
        buffer = bufnr,
        silent = true,
        desc = desc,
      })
    end

    map("n", "gd", vim.lsp.buf.definition, "Go to definition")
    map("n", "gD", vim.lsp.buf.declaration, "Go to declaration")
    map("n", "gi", vim.lsp.buf.implementation, "Go to implementation")
    map("n", "gr", vim.lsp.buf.references, "References")
    map("n", "K", vim.lsp.buf.hover, "Hover")
    map("n", "<leader>rn", vim.lsp.buf.rename, "Rename")
    map("n", "<leader>ca", vim.lsp.buf.code_action, "Code action")
    map("n", "<leader>e", vim.diagnostic.open_float, "Line diagnostic")
    map("n", "[d", vim.diagnostic.goto_prev, "Previous diagnostic")
    map("n", "]d", vim.diagnostic.goto_next, "Next diagnostic")
  end,
})

-- =========================
-- Diagnostics
-- =========================
vim.diagnostic.config({
  virtual_text = true,
  underline = true,
  severity_sort = true,
  float = {
    border = "rounded",
    source = true,
  },
})

-- =========================
-- Small quality-of-life mappings
-- =========================
local comment_prefix = function()
  local prefixes = {
    c = "// ",
    cpp = "// ",
    java = "// ",
    rust = "// ",
    vim = '" ',
    sh = "# ",
    bash = "# ",
    python = "# ",
    lua = "-- ",
    tex = "% ",
  }

  if prefixes[vim.bo.filetype] then
    return prefixes[vim.bo.filetype]
  end

  local prefix = vim.bo.commentstring:match("^(.-)%%s")
  if prefix then
    prefix = prefix:gsub("%s*$", " ")
    if prefix:match("%S") then
      return prefix
    end
  end

  return "# "
end

local toggle_comment = function(line1, line2)
  local prefix = comment_prefix()
  local prefix_pattern = vim.pesc(prefix)
  local should_uncomment = true

  for lnum = line1, line2 do
    local line = vim.fn.getline(lnum)
    if line:match("%S") and not line:match("^%s*" .. prefix_pattern) then
      should_uncomment = false
      break
    end
  end

  for lnum = line1, line2 do
    local line = vim.fn.getline(lnum)
    if line:match("%S") then
      if should_uncomment then
        line = line:gsub("^(%s*)" .. prefix_pattern, "%1", 1)
      else
        line = line:gsub("^(%s*)", function(indent)
          return indent .. prefix
        end, 1)
      end
      vim.fn.setline(lnum, line)
    end
  end
end

vim.keymap.set("n", "<leader>w", "<cmd>write<cr>", { desc = "Save" })
vim.keymap.set("n", "<leader>q", "<cmd>quit<cr>", { desc = "Quit" })
vim.keymap.set("n", "<leader>n", "<cmd>Explore<cr>", { desc = "Open netrw" })
vim.keymap.set("n", "<leader>ul", "<cmd>set list!<cr>", { desc = "Toggle whitespace markers" })
vim.keymap.set("n", "<leader>ff", function()
  require("conform").format({ async = true, lsp_format = "fallback" })
end, { desc = "Format file" })

for _, lhs in ipairs({ "<C-/>", "<C-_>" }) do
  vim.keymap.set("n", lhs, function()
    toggle_comment(vim.fn.line("."), vim.fn.line("."))
  end, { silent = true, desc = "Toggle line comment" })

  vim.keymap.set("x", lhs, function()
    toggle_comment(vim.fn.line("'<"), vim.fn.line("'>"))
  end, { silent = true, desc = "Toggle line comment" })
end
