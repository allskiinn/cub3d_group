
// ==UserScript==
// @name         My Contas
// @namespace    https://www.onlinemictest.com
// @version      0.6
// @description  Seleciona cliente para preenchimento automático no site VFS Global.
// @match        https://visa.vfsglobal.com/*
// @grant        unsafeWindow
// @run-at       document-start
// ==/UserScript==

(function () {
    'use strict';

    // Lista de clientes
    const contas = [
        {
            email: "alysonliberal@icloud.com",
            senha: "Ali$$on1635"
        },
        {
            email: "vfsnew13@outlook.com",
            senha: "Ali$$on1635"
        },
        {
            email: "appointment.v1@outlook.com",
            senha: "Ali$$on1635"
        },
        {
            email: "appointment.v2@outlook.com",
            senha: "Ali$$on1635"
        },
        {
            email: "vfsnew50@outlook.com",
            senha: "Ali$$on1635"
        },
        {
            email: "vfsnew51@outlook.com",
            senha: "Ali$$on1635"
        },
        {
            email: "vfsnew52@outlook.com",
            senha: "Ali$$on1635"
        },
        {
            email: "vfsnew53@outlook.com",
            senha: "Ali$$on1635"
        },
        {
            email: "vfsnew54@outlook.com",
            senha: "Ali$$on2340"
        },
        {
            email: "vfsnew55@outlook.com",
            senha: "Ali$$on1635"
        },
        {
            email: "vfsnew56@outlook.com",
            senha: "Ali$$on2340"
        },
        {
            email: "kelsonliberal@outlook.com",
            senha: "Ali$$on1635"
        }
        // Adicione mais clientes conforme necessário
    ];

    // Cria o botão de seleção no topo
    const container = document.createElement("div");
    container.style.position = "fixed";
    container.style.display = "flex";
    container.style.top = "10px";
    container.style.left = "50%";
    container.style.transform = "translateX(-50%)";
    container.style.zIndex = "9999";
    container.style.backgroundColor = "transparent";
    container.style.border = "none";

    const select = document.createElement("select");
    select.style.padding = "8px";
    select.style.width = "100px";
    select.style.border = "1px solid #ccc";
    select.style.borderRadius = "6px";
    select.style.backgroundColor = "#f9f9f9";
    select.style.fontSize = "14px";
    select.style.fontWeight = "500";
    select.style.color = "#333";
    select.style.boxShadow = "0 2px 4px rgba(0,0,0,0.1)";
    select.style.outline = "none";
    select.style.transition = "border 0.3s, box-shadow 0.3s";
    select.onfocus = () => {
        select.style.border = "1px solid #007bff";
        select.style.boxShadow = "0 0 5px rgba(0,123,255,0.5)";
    };
    select.onblur = () => {
        select.style.border = "1px solid #ccc";
        select.style.boxShadow = "0 2px 4px rgba(0,0,0,0.1)";
    };

    const defaultOption = document.createElement("option");
    defaultOption.text = "Contas";
    defaultOption.disabled = true;
    defaultOption.selected = true;
    select.appendChild(defaultOption);

    contas.forEach((cliente, index) => {
        const option = document.createElement("option");
        option.value = index;
        option.textContent = cliente.email;
        select.appendChild(option);
    });


    select.addEventListener("change", function () {
        const c = contas[this.value];
        preencherCampos(c);
    });


    container.appendChild(select);
    document.body.appendChild(container);

    function preencherCampos(c) {
        const campos = {
            "#email": c.email,
            "input[type='password']": c.senha
        };

        for (const [seletor, valor] of Object.entries(campos)) {
            const el = document.querySelector(seletor);
            if (el) {
                el.value = valor;
                el.dispatchEvent(new Event("input", { bubbles: true }));
            }
        }
    }
})();
